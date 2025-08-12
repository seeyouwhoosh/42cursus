# Manejo básico de ventanas
* `mlx_init()`: inicia una conexión con la pantalla
* `mlx_new_window(mlx, 1920, 1080, "test window")`: crea una ventana en la instancia anterior
* `mlx_loop(mlx)`: inicia el loop para que la ventana no abra y cierre al instante. 


# Conceptos para imágenes
Dada la siguiente estructura:
```c
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
```
Tenemos que aclarar algunas cosas:
* `bits_per_pixel`: Se refiere a la cantidad de bits que se necesita para representar el color en cada pixel.Esto limita el número de colores que se representan en la imagen
* `endian`: El orden en que los bytes se almacenan en memoria. `little endian` significa que el byte más pequeño se almacena primero
  * Ejemplo: 0x4A3B2C1D se codificaría en memoria en la secuencia {4A, 3B, 2C, 1D} en `big endian`. En el sistema `little endian` se codificaría como {1D, 2C, 3B, 4A},