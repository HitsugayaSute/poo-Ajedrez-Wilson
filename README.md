#Ajedrez con SFML

¡Un ajedrez funcional con interfaz gráfica y una IA básica para jugar!

## ¿Qué tiene?

- Tablero visual con casillas de colores.
- Piezas con imágenes (si las pones en la carpeta assets).
- Juegas con las blancas (con el ratón).
- La máquina juega con las negras usando una IA sencilla.
- Respeta movimientos básicos: peones, torres, caballos, alfiles, reina, rey.
- Detecta jaque, jaque mate y tablas por falta de movimientos.
- Promoción automática de peón a reina.

## ¿Cómo lo compilo y ejecuto?

### Necesitas tener instalado:

- **MinGW** (por ejemplo TDM-GCC) - [descarga aquí](https://jmeubank.github.io/tdm-gcc/)
- **SFML 2.6.1 para MinGW 64-bit** - [descarga aquí](https://www.sfml-dev.org/download/sfml/2.6.1/)

### Pasos rápidos:

1. Descarga SFML y extrae en `C:\SFML-2.6.1`.
2. Coloca las 12 imágenes de las piezas (blancas y negras) en una carpeta `assets` (dentro del proyecto). Los nombres deben ser: wp.png, wr.png, wn.png, wb.png, wq.png, wk.png, bp.png, br.png, bn.png, bb.png, bq.png, bk.png.  
   También necesitas una fuente `arial.ttf` en la misma carpeta (puedes copiarla de Windows/Fonts).
3. Abre el archivo `ejecutar.bat` con un editor y ajusta las rutas de SFML y MinGW si están en distinto lugar.
4. Haz doble clic en `ejecutar.bat`. Se compilará todo y se abrirá el juego.

Si todo sale bien, verás la ventana del ajedrez. Presiona **ESPACIO** para empezar.

## ¿Cómo se juega?

- Haz clic en una pieza blanca (se resalta en rojo).
- Luego clic en una casilla destino (si es un movimiento legal, la pieza se mueve).
- Después juega la máquina automáticamente.
- Cuando la partida termina, sale un mensaje de victoria o derrota.

## ¿Problemas?

- **Si pide DLLs como `libgcc_s_seh-1.dll`**: El script ya intenta compilar en modo estático. Si aún así falla, copia las DLLs de MinGW (desde `C:\TDM-GCC-64\bin`) a la carpeta donde está `ajedrez.exe`.
- **Las piezas no se ven**: Asegúrate de tener las imágenes en `assets` y que se llamen exactamente como se espera. También puedes modificar el código para que dibuje las piezas como letras (más fácil).
- **No compila**: Revisa que las rutas de SFML en el batch sean correctas y que tengas todos los archivos .cpp en las carpetas adecuadas.

## Cosas que faltan (para otro día)

- Enroque
- Captura al paso
- Promoción a otra pieza que no sea reina
- Guardar/cargar partida (está medio hecho)

## ¡Diviértete!

Si te atasca la IA, puedes cambiar la profundidad en `VentanaJuego.cpp` (línea donde llama a `ia.decidir`). A mayor profundidad, más lento pero más listo.

Cualquier duda, pregunta.
