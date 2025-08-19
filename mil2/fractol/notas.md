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

# Colores
Usamos el formato TRGB tal que así: `0xTTRRGGBB`

|	T	|	R	|	G	|	B	|
|_ _ _ _|_ _ _ _|_ _ _ _|_ _ _ _|

Cada int usa 4 bytes, 32 bits. En hexadecimal, podemos decir se dividen en 4 trozos, con 8 bits en cada trozo. Entonces, mediante bitwise operators, se puede manipular como:
```c
int	get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
```
# Interacciones
Me ha costado entenderlo, con los eventos y máscaras... De verdad, no lo podrían llamar distinto...

Esta librería tiene una función para mapear interacciones genéricamente:
```
void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
```

En donde:
* El puntero a `win_ptr` es al puntero void de la ventana
* `x_event` corresponde a elementos de la siguiente tabla (estos son los más usado, pero hay más), y su correspondiente prototipo de función

| Hooking event | Code	| Prototype											|
|---------------|-------|---------------------------------------------------|
| ON_KEYDOWN	| 2		| int (*f)(int keycode, void *param)				|
| ON_KEYUP		| 3		| int (*f)(int keycode, void *param)				|
| ON_MOUSEDOWN*	| 4		| int (*f)(int button, int x, int y, void *param)	|
| ON_MOUSEUP	| 5		| int (*f)(int button, int x, int y, void *param)	|
| ON_MOUSEMOVE	| 6		| int (*f)(int x, int y, void *param)				|
| ON_EXPOSE*	| 12	| int (*f)(void *param)								|
| ON_DESTROY	| 17	| int (*f)(void *param)								|

* `x_mask` corresponde al tipo de interacción que recoge del usuario
* `param` es el parámetro a pasar cada vez que se ejecuta el evento (a la función)

Afortunadamente, hay funciones que ya nos definen los tipos de evento más comunes:
```c
/* Hook into mouse events. This will trigger every time you click somewhere in the given screen. Do mind that currently these mouse events barely work, it is therefore suggested to not use them. */
int		mlx_mouse_hook(void *win_ptr, int (*f)(), void *param);

/* Hook into key events. This will trigger every time a key is pressed in a focused window. Unfocused windows will not register any key events. */
int		mlx_key_hook(void *win_ptr, int (*f)(), void *param);

/* Hook into the loop */
int		mlx_loop_hook(void *mlx_ptr, int (*f)(), void *param);
```

# Interacciones
Me ha costado entenderlo, con los eventos y máscaras... De verdad, no lo podrían llamar distinto...

Esta librería tiene una función para mapear interacciones genéricamente:
```
void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
```

En donde:
* El puntero a `win_ptr` es al puntero void de la ventana
* `x_event` corresponde a elementos de la siguiente tabla (estos son los más usado, pero hay más), y su correspondiente prototipo de función

| Hooking event | Code	| Prototype											|
|---------------|-------|---------------------------------------------------|
| ON_KEYDOWN	| 2		| int (*f)(int keycode, void *param)				|
| ON_KEYUP		| 3		| int (*f)(int keycode, void *param)				|
| ON_MOUSEDOWN*	| 4		| int (*f)(int button, int x, int y, void *param)	|
| ON_MOUSEUP	| 5		| int (*f)(int button, int x, int y, void *param)	|
| ON_MOUSEMOVE	| 6		| int (*f)(int x, int y, void *param)				|
| ON_EXPOSE*	| 12	| int (*f)(void *param)								|
| ON_DESTROY	| 17	| int (*f)(void *param)								|

* `x_mask` corresponde al tipo de interacción que recoge del usuario
* `param` es el parámetro a pasar cada vez que se ejecuta el evento (a la función)

Afortunadamente, hay funciones que ya nos definen los tipos de evento más comunes:
```c
/* Hook into mouse events. This will trigger every time you click somewhere in the given screen. Do mind that currently these mouse events barely work, it is therefore suggested to not use them. */
int		mlx_mouse_hook(void *win_ptr, int (*f)(), void *param);

/* Hook into key events. This will trigger every time a key is pressed in a focused window. Unfocused windows will not register any key events. */
int		mlx_key_hook(void *win_ptr, int (*f)(), void *param);

/* Hook into the loop */
int		mlx_loop_hook(void *mlx_ptr, int (*f)(), void *param);
```