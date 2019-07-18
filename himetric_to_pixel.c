/**
 *  File   : himetric_to_pixel.c
 *  Author : leandro.pedro@intech-automacao.com.br
 *  Date   : 2016/05/15
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

#define himetric_to_pixel(h) (h * 96 / 2540)
#define pixel_to_himetric(p) (p * 2540 / 96)

void show_help ()
{
  printf("\nUse: himetric [-h2p] [-p2h] value\n\n");
  printf("Options:\n\t-h2p\tHimetric to pixels.\n\t-p2h\tPixels to himetric.\n\n");
  printf("Allows use of math expression as argument: 12+32-5+...\n");
}

/* Copy conversion result to clipboard. */
void _cdecl copy_to_clipboard(const char* output)
{
  const size_t len = strlen(output) + 1;
  HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
  memcpy(GlobalLock(hMem), output, len);
  GlobalUnlock(hMem);
  OpenClipboard(0);
  EmptyClipboard();
  SetClipboardData(CF_TEXT, hMem);
  CloseClipboard();
}

int main(int argc, char *argv[])
{
  double value;
  char *end, *unit;
  char output[50];

  // Set locale as same as current OS.
  setlocale(LC_NUMERIC, "");

  if (argc != 3) {
    // None arguments.
    show_help();
    return EXIT_FAILURE;
  } else {
    // Value to be converted.
    value = strtod(argv[2], &end);
	
    // Consumes the operation symbols
    while (strlen(end) > 0){
        if ((char) end[0] == '+'){
            strcpy(&end[0], &end[1]);
            value += strtod(end, &end);
        }else if ((char) end[0] == '-'){
            strcpy(&end[0], &end[1]);
            value -= strtod(end, &end);
        }else if ((char) end[0] == '*'){
            strcpy(&end[0], &end[1]);
            value *= strtod(end, &end);
        }else if ((char) end[0] == '/'){
            strcpy(&end[0], &end[1]);
            value /= strtod(end, &end);
        } else {
		        show_help();
		        return EXIT_FAILURE;	
		}	
    }	

    // Checks if value is a number.
    if (strcmp(end, "")) {
      // TODO: Value ins't a number.
      printf("Value ins't a number.\n");
      return EXIT_FAILURE;
    }
  }

  // Check argument.
  if (!strcmp(argv[1], "-h2p")) {         // Himetric to Pixel.
    value = himetric_to_pixel(value);
    unit = "pixels";
  } else if (!strcmp(argv[1], "-p2h")) {  // Pixel to Himetric.
    value = pixel_to_himetric(value);
    unit = "himetric";
  } else if (!strcmp(argv[1], "/?")) {    // Help.
    show_help();
    return EXIT_FAILURE;
  } else {
    printf("No valid arguments.\n");
    return EXIT_FAILURE;
  }

  // Print result on console.
  printf("%f %s\n", value, unit);

  // Copy result to clipboard.
  snprintf(output, 50, "%f", value);
  copy_to_clipboard(output);

  return EXIT_SUCCESS;
}
