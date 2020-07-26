### Pregunta 4

Considera un proceso con 4 páginas lógicas, numeradas del 0 al 3. La tabla de páginas del proceso consta de las siguientes asignaciones de números de páginas lógicas a números de trama fı́sica: ( 0, 11 ) , ( 1, 35 ) , ( 2, 3 ) , ( 3, 1 ) . El proceso se ejecuta en un sistema con direcciones virtuales de 16 bits y un tamaño de página de 256 bytes. Se garantiza que este proceso accede a la dirección virtual 770. Responde las siguientes preguntas, mostrando los cálculos adecuados.
1. ¿A qué número de página lógica corresponde esta dirección virtual?
2. ¿A qué dirección fı́sica se traduce esta dirección virtual?

* Primero hallemos el formato de direccion virtual y luego fisica, en la siguiente imagen vemos el procedimiento de resolucion de la pregunta:

![](/home/jesus/Escritorio/SistemasOperativosAvanzado/Practicas/pc-2/Practica-Calificada2-CC571/pregunta4.png)


### Pregunta 7

Considera un asignador de memoria que utiliza el algoritmo de asignación buddy para satisfacer las solicitudes de memoria. El asignador comienza con un heap de tamaño 4KB (4096 bytes). El programa de usuario realiza las siguientes solicitudes al asignador (todos los tamaños solicitados están en bytes): ptr1 = malloc (500); ptr2 = malloc (200); ptr3 = malloc (800); ptr4 = malloc (1500). Si el encabezado agregado por el asignador tiene menos de 10 bytes de tamaño. Puedes hacer cualquier suposición sobre la implementación del algoritmo de asignación buddy que sea consistente con la descripción en clase.

1. Dibuja una figura que muestre el estado del heap después de completar estas 4 asignaciones. Tu figura debe mostrar qué partes del heap están asignadas y cuáles son libres, incluidos los tamaños de los diversos bloques asignados y libres.
2. Ahora, supongamos que el programa de usuario libera asignaciones de memoria de ptr2, ptr3 y ptr4. Dibuja una figura que muestre el estado del heap una vez más, después de que se libere memoria y el algoritmo de asignación haya tenido la oportunidad de realizar cualquier posible coalescing.

* Para el item **a** mostramos la respuesta en la siguiente imagen:
![](/home/jesus/Escritorio/SistemasOperativosAvanzado/Practicas/pc-2/Practica-Calificada2-CC571/pregunta7a.png)

* Para el item **b** mostramos la respuesta en la siguiente imagen:
![](/home/jesus/Escritorio/SistemasOperativosAvanzado/Practicas/pc-2/Practica-Calificada2-CC571/pregunta7b.png)