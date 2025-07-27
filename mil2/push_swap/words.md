# Comprensión inicial del proyecto
Hay dos pilas de cosas y unas cuántas instrucciones para manipular estos stacks.

El objetivo es esribir un programa que calcule y printee la secuencia más corta de instrucciones para ordenar esos números.

> The most efficient sorting method can vary depending on the arrangement of
integers.

## Operaciones
1. Swap: intercambiar los primeros dos elementos de la lista
sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one element or none.
sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one element or none.
ss : sa and sb at the same time.

1. Push: Coger el primer elemento de B y ponerlo en A
pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

1. Rotate: Rotar todos los elementos, el primero se vuelve el último
ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
rr : ra and rb at the same time.

1. Rotar todos los elementos pero al revés, el último elemento se vuelve el primero
rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.

# Algoritmos mencionados
1. turco
2. butterfly
3. quicksort
4. radix [no]

# Funciones que necesito, para empezar
* Uno que me parsee los argumentos:
  1. Comprobar que todos son números
  2. Comprobar que no superan los límites de int
  3. Meter los números en listas
* Que compruebe que no hay ningún número ilegal (que a_i perteneciente al conjunto A sea distinto de a_j para todo i distinto de j)
* Que compruebe si está en orden o no.
* Cada una de las funciones operaciones que nos piden, con su nota de impresión para saber que se ha realizado.

# Lista de tareas
- [ ] Terminar de crear las listas del input (parseo)
- [ ] Crear la función para comprobar que no hay ningún número ilegal en la lista
- [ ] Crear una función que compruebe si la lista está en orden (creciente, creo) o no. 
- [ ] Crear las funciones de las operaciones
- [ ] Investigar los algoritmos recomendados y mirar qué se pide realmente, cómo implementarlo con las funciones que tenemos, ó si es necesario hacer por casos, por ejemplo, si solo hay dos números, tres, cuatro, and so on.
- [ ] Proseguir.