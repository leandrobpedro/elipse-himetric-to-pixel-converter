# Elipse E3/Power Himetric To Pixel Converter

O E3 utiliza o *Himetric* para definir as coordenadas dos objetos de tela, e *Pixel* para definir o tamanho dos `'Frames'` que serão utilizados para mostrar as telas. `1 pixel` equivale a aproximadamente `26.4 himetric`. Este executável tem como objetivo facilitar esta conversão de himetric para pixel ou vice-versa conforme  [KB-25504](http://kb.elipse.com.br/en-us/questions/486/KB-25504%3A+Convertendo+HIMETRIC+para+PIXEL.).

## Introdução
* Baixe o executável disponível em **Releases**
* Coloque o arquivo no diretório em que preferir, e.g.: `c:\temp\himetric.exe`
* Adicione o diretório à variável `$PATH` (opcional):
```bat
set PATH=%PATH%;C:\temp
```

## Comandos
```bat
Use: himetric [-h2p] [-p2h] value

Options:
        -h2p    Himetric to pixels.
        -p2h    Pixels to himetric.
```
## Exemplos
No *prompt* de comando do *Windows*, navegue até o diretório onde se encontra o executável (caso não tenha adiconado ao `PATH`).
```bat
cd c:\temp
```
```bat
c:\temp>himetric -p2h 48
1270,000000 himetric

c:\temp>himetric -h2p 2540
96,000000 pixels
```
O resultado será automaticamente copiado para o *clipboard*.

## Autor
* **Leandro B. Pedro** - [In-Tech Automação e Sistemas](http://www.intech-automacao.com.br/)
