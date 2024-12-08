int n, row, col;printf("Enter the number of rows: ");scanf("%d", &n);
for (row = n; row >= 1; row--) {
for (col=1;col<=row; col++) {
printf("%d ",col);
 }printf("\n");
 }