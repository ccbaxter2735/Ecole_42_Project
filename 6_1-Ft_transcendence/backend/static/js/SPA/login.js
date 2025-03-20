import { handleLocation } from "./router.js";
import { translations } from "./translation.js";
import { fetchConfig, getFetchConfigWithCSRF } from "./router.js";

export function isAlphanumeric(str) {
  return /^[a-zA-Z0-9]+$/.test(str);
}

export function showNotification(message, type) {
  const currentLanguage = localStorage.getItem("lang") || "en";
  type = type || "info";

  let notificationsContainer = document.getElementById(
    "notifications-container",
  );
  if (!notificationsContainer) {
    notificationsContainer = document.createElement("div");
    notificationsContainer.id = "notifications-container";
    notificationsContainer.style.position = "fixed";
    notificationsContainer.style.top = "20px";
    notificationsContainer.style.left = "50%";
    notificationsContainer.style.transform = "translateX(-50%)";
    notificationsContainer.style.zIndex = "9999";
    notificationsContainer.style.width = "80%";
    notificationsContainer.style.maxWidth = "500px";
    document.body.appendChild(notificationsContainer);
  }

  var alertDiv = document.createElement("div");
  alertDiv.className = "alert alert-" + type + " alert-dismissible fade show";
  alertDiv.style.boxShadow = "0 4px 6px rgba(0, 0, 0, 0.1)";
  alertDiv.style.marginBottom = "10px";
  alertDiv.innerHTML = `
    ${translations[currentLanguage][message] || message}
    <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
  `;

  notificationsContainer.appendChild(alertDiv);

  setTimeout(function () {
    alertDiv.classList.remove("show");
    setTimeout(() => alertDiv.remove(), 150);
  }, 5000);
}

export async function logout() {
  try {
    var config = await getFetchConfigWithCSRF();
    const response = await fetch("/api/game/logout/", {
      ...config,
      method: "POST",
    });

    if (response.ok) {
      showNotification("logout_success", "success");
    }

    window.history.pushState({}, "", "/login");
    handleLocation();
  } catch (error) {
    showNotification("network_error", "danger");
  }
}
async function handleForm(url, formData, buttonId) {
  var button = document.getElementById(buttonId);
  button.disabled = true;

  try {
    var config = await getFetchConfigWithCSRF();
    var response = await fetch(url, {
      ...config,
      method: "POST",
      headers: {
        ...config.headers,
        "Content-Type": "application/json",
      },
      body: JSON.stringify(formData),
    });

    var data = await response.json();

    if (!response.ok) {
      if (response.status === 401) {
        throw new Error("invalid_credentials");
      } else if (response.status === 500) {
        throw new Error("server_error");
      } else {
        throw new Error(data.message || "server_error");
      }
    }

    if (url.includes("login")) {
      showNotification("login_success", "success");
    }

    document.getElementById("navbar").style.display = "block";
    window.history.pushState({}, "", "/");
    handleLocation();
    return data;
  } catch (error) {
    throw error;
  } finally {
    button.disabled = false;
  }
}
async function handleLogin(event) {
  event.preventDefault();
  const username = document.getElementById("username").value.trim();
  const password = document.getElementById("password").value.trim();

  if (!username || !password) {
    showNotification("fill_fields_error", "danger");
    return;
  }

  if (!isAlphanumeric(username)) {
    showNotification("username_alphanumeric_only", "danger");
    return;
  }

  try {
    await handleForm("/api/game/login/", { username, password }, "loginBtn");
  } catch (error) {
    showNotification("invalid_credentials", "danger");
  }
}

async function handleSignup(event) {
  event.preventDefault();
  const username = document.getElementById("signupUsername").value.trim();
  const password = document.getElementById("signupPassword").value;

  if (!username || !password) {
    showNotification("fill_fields_error", "danger");
    return;
  }
  if (!isAlphanumeric(username)) {
    showNotification("username_alphanumeric_only", "danger");
    return;
  }
  if (username.length > 20) {
    showNotification("username_length_error", "danger");
    return;
  }

  if (password.length > 20) {
    showNotification("password_length_error", "danger");
    return;
  }

  if (username.length < 3) {
    showNotification("username_length_min_error", "danger");
    return;
  }

  if (password.length < 3) {
    showNotification("password_length_min_error", "danger");
    return;
  }

  try {
    await handleForm(
      "/api/game/signup/",
      { username, password },
      "submitSignUpBtn",
    );

    var modal = bootstrap.Modal.getInstance(
      document.getElementById("signupModal"),
    );
    modal.hide();
    showNotification("signup_success", "success");
  } catch (error) {
    showNotification("username_exists", "danger");
  }
}

export function setupLoginPageEvents() {
  document.getElementById("navbar").style.display = "none";
  document.getElementById("loginForm").addEventListener("submit", handleLogin);
  document
    .getElementById("signupForm")
    .addEventListener("submit", handleSignup);
}
