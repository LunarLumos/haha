 int n, a = 2, sum = 0;
printf("Enter the last number of this series: ");scanf("%d", &n);
 for (;;) {
 printf(" %d", a);
sum = sum + a;
a = a + 2;
 if (a > n) {
break;
}
printf(" +");
}printf(" = %d\n", sum);
