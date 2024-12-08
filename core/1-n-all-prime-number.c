int num, i, j, count = 0;
printf("Enter the last number: ");scanf("%d", &num);
printf("Prime numbers up to %d: ", num);
for (i = 2; i <= num; i++) {
 int is_prime = 1;
for (j = 2; j <= i / 2; j++) {
 if (i % j == 0) {
is_prime = 0; 
 break;
}
 }
if (is_prime) {
printf("%d ", i);
count++;
 }
} printf("\nTotal prime numbers = %d.\n", count);