int x;printf("[-] Enter your Exam marks: ");scanf("%d", &x);
 if (x >= 80) {
printf("\n[+] Outstanding! You scored %d marks, which means you got an A+!\n", x);
} else if (x >= 75) {
 printf("\n[+] Great job! You scored %d marks, which means you got an A!\n", x);
 } else if (x >= 70) {
printf("\n[+] Well done! You scored %d marks, which means you got an A-!\n", x);
 } else if (x >= 60) {
printf("\n%d marks = B!\n", x);
} else if (x >= 55) {
printf("\n %d marks = B-!\n", x);
 } else if (x >= 50) {
printf("\n %d marks = C+.\n", x);
} else if (x >= 45) {
 printf("\n %d marks = C.\n", x);
 } else {
printf("\n %d marks Which is Wrong or Fail!\n", x);
 }
