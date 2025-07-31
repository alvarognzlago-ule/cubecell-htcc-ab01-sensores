# cubecell-htcc-ab01-sensores

**Códigos de ejemplo para conectar la placa CubeCell HTCC-AB01 a distintos sensores de medición ambiental y meteorológica.**

El objetivo de este repositorio es facilitar la integración de sensores comunes en proyectos IoT basados en CubeCell, orientados a aplicaciones agrícolas, monitorización ambiental y experimentación educativa.

---

## 📁 Estructura del repositorio

- `Documentación de sensores/`  
  Información técnica, esquemas de conexión y detalles de los sensores soportados.

- `cubecell-agua/`  
  Códigos y ejemplos para medir temperatura del agua (ej: sensor DS18B20 impermeable).

- `cubecell-suelo/`  
  Ejemplos de lectura de humedad de suelo con CubeCell.

---

## ⚙️ Requisitos

- **Placa:** CubeCell HTCC-AB01  
- **IDE recomendado:** [Arduino IDE](https://www.arduino.cc/en/software)  
- **Librerías necesarias:**  
  - [CubeCell Arduino](https://github.com/HelTecAutomation/ASR650x-Arduino)
  - [OneWire](https://www.arduino.cc/reference/en/libraries/onewire/) (para DS18B20)
  - [DallasTemperature](https://www.arduino.cc/reference/en/libraries/dallastemperature/) (para DS18B20)
  - *Otras según el sensor usado*

---

## 🚀 Instalación y uso rápido

1. Instala **Arduino IDE** y añade el soporte CubeCell siguiendo la [guía oficial](https://github.com/HelTecAutomation/ASR650x-Arduino).
2. Descarga o clona este repositorio:
    ```bash
    git clone https://github.com/tuusuario/cubecell-htcc-ab01-sensores.git
    ```
3. Abre el archivo `.ino` correspondiente al sensor que quieras usar.

---

## 🧪 Ejemplo rápido

### Temperatura de agua (DS18B20)

1. Conecta el sensor DS18B20 a tu CubeCell (ver carpeta de documentación).
2. Abre `cubecell-agua.ino` en Arduino IDE.
3. Sube el código a la placa.
4. Abre el monitor serie para ver la temperatura.

### Humedad de suelo

1. Conecta el sensor de humedad de suelo según el esquema.
2. Abre `cubecell-suelo.ino`.
3. Sube el código y revisa los datos por monitor serie.

---

## 📄 Licencia

MIT. Puedes usar, modificar y compartir este código citando la fuente.

---

