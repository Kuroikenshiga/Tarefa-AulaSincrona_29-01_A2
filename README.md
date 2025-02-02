## Tarefa da aula síncrona do dia 29 de janeiro de 2025 - Atividade 1

### 🗒️Enunciado:
Com o emprego da função add_alarm_in_ms(), presente na ferramenta Pico SDK, projete um sistema de temporização para o acionamento de LEDs, que atua a partir do clique em um botão (pushbutton). Nesta prática, será necessário simular os seguintes componentes

### 📝Objetivos:
- Caso o usuário clique no botão (pushbutton), os três LEDs serão ligados (todos em nível alto). A partir da primeira rotina de atraso, ocorrerá uma mudança de estado para dois LEDs ligados e, em seguida, apenas um. Obs.: veja o vídeo associado a esta prática no link presente na Figura 3.
- O temporizador do alarme deve ser ajustado para um atraso de 3 segundos (3.000ms), entre os estados de acionamento dos LEDs.
- A mudança de estado dos LEDs deve ser implementa em funções de call-back do temporizador, a exemplo da rotina trabalhada na aula síncrona turn_off_callback().
- O botão só pode alterar o estado dos LEDs quando o último LED for desligado. Deste modo, durante a execução das rotinas de temporização, o botão não pode iniciar uma nova chamada da função call-back.
- Com o emprego da Ferramenta Educacional BitDogLab, faça um experimento com o código deste exercício utilizando o LED RGB – GPIOs 11, 12 e 13 e o Botão A, GPIO 05.
- Opcional: Implementar uma rotina em software para atenuação
do efeito bouncing no botão (software debounce).


### ❗Requisitos para execução do projeto (Software)
- Compilador Arm gcc instalado
- PICO SDK intalado
- Visual Studio Code instalado
- Extensão do Respberry Pi Pico instalada
- Extensão do Wokwi Simulator instalada e configurada
- Extensões Cmake e Cmake tools instaladas 

### ❗Requisitos para execução do projeto (Hardware)
- Kit de desenvolvimento BitDogLab

### Instruções para a execução do projeto

1. Baixe o projeto na sua maquina atráves do cmd pelo comando: 
    ```bash 
    git clone https://github.com/Kuroikenshiga/Tarefa-AulaSincrona_29-01_A2.git
2. Abra o Visual Studio Code.
3. No menu lateral esquerdo, encontre a extensão do Respberry Pi Pico e clique nela.
4. Selecione a opção "Import Project"
5. No campo "Location" clique no botão "Change" e selecione o projeto que você acabou de baixar na sua maquina.
6. Clique no botão "Import"
7. Após carregar todos os arquivos necessários, clique na opção "Compile" presente no menu inferior direito.

