FROM ubuntu:latest

# Gerekli paketleri yükle
RUN apt-get update && apt-get install -y \
    mpich \
    libomp-dev \
    g++ \
    && rm -rf /var/lib/apt/lists/*

# Çalışma dizinini ayarla
WORKDIR /app

# Kaynak kodları kopyala
COPY src/main.cpp .
COPY src/mpi_runner.sh .

# Derleme işlemi (MPI ve OpenMP desteğiyle)
RUN mpic++ -fopenmp main.cpp -o mpi_main.out

# Çalıştırma komutu
CMD ["bash", "mpi_runner.sh"]
