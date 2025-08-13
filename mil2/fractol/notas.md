# Manejo básico de ventanas
* `mlx_init()`: inicia una conexión con la pantalla
* `mlx_new_window(mlx, 1920, 1080, "test window")`: crea una ventana en la instancia anterior
* `mlx_loop(mlx)`: inicia el loop para que la ventana no abra y cierre al instante. 


# Conceptos para imágenes
Dada la siguiente estructura, que la emplearemos para establecer pixeles de imagen:
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
* `bits_per_pixel`: Se refiere a la cantidad de bits que se necesita para representar el color en cada pixel. Esto limita el número de colores que se representan en la imagen. Generalmente múltiplo de 8.
* `endian`: El orden en que los bytes se almacenan en memoria. `little endian` significa que el byte más pequeño se almacena primero
  * Ejemplo: 0x4A3B2C1D se codificaría en memoria en la secuencia {4A, 3B, 2C, 1D} en `big endian`. En el sistema `little endian` se codificaría como {1D, 2C, 3B, 4A},
* `line_length`: Cuántos bytes ocupa cada fila de imagen

Para sacar la posición que ocupa un pixel en la memoria, calculamos el offset:
`int offset = (y * line_length + x * (bits_per_pixel / 8));`
											|-> se me olvida, pero un byte son 8 bits

Con esto crearemos nuestro propio `pixel_put`, debido a que el que nos dan (`mlx_pixel_put()`) intenta pushear el pixel inmediatamente a la ventana (calcular la posición -> actualizar el framework -> dibujarlo para un único píxel). La solución que propone nuestra función es actualizar el píxel en memoria, y esta mostrará la imagen de una.

Función sustituyente del mlx_pixel_put:
```c
void	mmlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * line_length + x * (bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
```