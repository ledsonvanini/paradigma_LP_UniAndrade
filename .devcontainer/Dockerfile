FROM gcc:14

# Instalar dependências necessárias
RUN apt-get update && apt-get install -y \
    build-essential \
    libsdl2-dev \
    libsdl2-image-dev \
    libsdl2-mixer-dev \
    libsdl2-ttf-dev \
    libraylib-dev \
    vim

# Limpar cache para manter a imagem menor
RUN apt-get clean && rm -rf /var/lib/apt/lists/*
