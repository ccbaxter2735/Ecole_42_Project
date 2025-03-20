import { translations, translatePage } from "./translation.js";
import { setupPlayPageEvents } from "./play.js";
import { setupProfilePageEvents } from "./profile.js";
import { setupLeaderboardPageEvents } from "./leaderboard.js";
import { logout, setupLoginPageEvents } from "./login.js";

export const fetchConfig = {
  credentials: "include",
  headers: {},
};

export async function getCSRFToken() {
  const response = await fetch("api/game/get_csrf_token/", {
    method: "GET",
    credentials: "include",
  });
  const data = await response.json();
  return data.csrfToken;
}

export async function addCSRFToHeaders(existingHeaders = {}) {
  const csrfToken = await getCSRFToken();
  return {
    ...existingHeaders,
    "X-CSRFToken": csrfToken,
  };
}

export async function getFetchConfigWithCSRF() {
  return {
    ...fetchConfig,
    headers: await addCSRFToHeaders(fetchConfig.headers),
  };
}

const routes = {
  "/": "./html/home.html",
  "/login": "./html/login.html",
  "/play": "./html/play.html",
  "/game": "./html/game.html",
  "/profile": "./html/profile.html",
  "/leaderboard": "./html/leaderboard.html",
};

const pageSetups = {
  "/play": setupPlayPageEvents,
  "/login": setupLoginPageEvents,
  "/leaderboard": setupLeaderboardPageEvents,
  "/profile": setupProfilePageEvents,
};
export async function handleLocation() {
  const path = window.location.pathname;
  let dataProfile = null;

  if (path !== "/login") {
    try {
      const headersWithCSRF = await addCSRFToHeaders(fetchConfig.headers);
      const response = await fetch("/api/game/profile", {
        ...fetchConfig,
        headers: headersWithCSRF,
      });

      if (
        response.url.includes("/accounts/login/") ||
        [401, 403, 500].includes(response.status)
      ) {
        window.history.pushState({}, "", "/login");
        return handleLocation();
      }

      dataProfile = await response.json();
    } catch (error) {
      console.error("Error fetching profile:", error);
      window.history.pushState({}, "", "/login");
      return handleLocation();
    }
  }

  const htmlPath = routes[path];
  const html = await fetch(htmlPath).then((r) => r.text());
  document.getElementById("content").innerHTML = html;

  if (dataProfile && dataProfile.lang) {
    await translatePage(dataProfile.lang);
  } else {
    await translatePage("en");
  }

  pageSetups[path]?.();
  document.documentElement.classList.toggle("game-page", path === "/game");
}

function route(event) {
  event?.preventDefault();
  window.history.pushState({}, "", event.target.href);
  handleLocation();
}

window.route = route;
window.logout = logout;

window.addEventListener("popstate", () => {
  const path = window.location.pathname;
  if (path === "/game") {
    window.history.replaceState({}, "", "/play");
  }
  handleLocation();
});

document.addEventListener("DOMContentLoaded", async () => {
  window.history.replaceState({}, "", "/");
  await handleLocation();
});
