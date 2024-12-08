char upperChar, lowerChar;
printf("Enter a character: ");scanf(" %c", &upperChar);
lowerChar = upperChar + 32;
upperChar = lowerChar - 32;
printf("The lowercase character is '%c'.\n", lowerChar);
printf("The uppercase character is '%c'.\n", upperChar);