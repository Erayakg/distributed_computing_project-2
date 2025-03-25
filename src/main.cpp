#include <iostream>
#include <omp.h>
#include <mpi.h>

void openmp_task() {
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        std::cout << "OpenMP Thread " << thread_id << " is working.\n";
    }
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    std::cout << "MPI Process " << world_rank << " out of " << world_size << " is running.\n";

    openmp_task(); // Her düğüm içinde OpenMP çalıştır

    MPI_Finalize();
    return 0;
}
