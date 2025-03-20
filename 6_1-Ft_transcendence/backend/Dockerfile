FROM python:3.9-slim
RUN apt-get update && apt-get install -y --no-install-recommends \
    postgresql-client \
    libpq-dev \
    netcat-traditional \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /app
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt
COPY . .
COPY config.sh /app/
COPY dbshow.sh .
RUN chmod +x /app/config.sh
RUN chmod +x dbshow.sh

RUN mkdir -p /app/backend/media/images
RUN chmod -R 755 /app/backend/media
COPY static/images/profile.jpg /app/media/images/default-profile.jpg

ENTRYPOINT [ "/app/config.sh" ]
EXPOSE 8000
