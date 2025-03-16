FROM gcc:14

# Instala ferramentas adicionais, se necessário
RUN apt-get update && apt-get install -y vim
