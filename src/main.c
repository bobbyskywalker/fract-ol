#include "../lib/minilibx-linux/mlx.h"

int main()
{
    void *mlx_ptr = mlx_init();
    void *mlx_window = mlx_new_window(mlx_ptr, 100, 100, "guwno");
    mlx_loop(mlx_ptr);
    return (0);
}
