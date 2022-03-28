// Youssef Ashraf Mohamed >> sec 2 >> bench number 52
// Pseudocode to get the inverse of a non singular square matrix
// Note in for loops steps is by deafult = 1
start
int n,i,j
INPUT n // n*n dimension of the matrix
int arr[n][2*n]
// Input the matrix from the user
FOR i: 0 to n-1
   FOR j : 0 to n-1
       INPUT arr[i][j]
   END FOR
END FOR
    // put identity matrix within the augmented matrix
FOR i:0 to n-1
    FOR j:n to 2*n-1
       set arr[i][j] to 0
    END FOR
END FOR
// put 1s on the diagonal of the identity matrix
FOR i:0 to n-1
    FOR j:0 to 2*n-1
      IF  j==i+n
        set arr[i][j] to 1
      END IF
    END FOR
END FOR
// swapping rows by sorting them on their leading numbers of 1st column
FOR i:n-1 to 1 step down by 1
      IF  arr[i-1][0]<arr[i][0]
              swap (arr[i-1],arr[i])
         // swapping the two rows we can use for loop or pointers in implementation
      END IF
END FOR
// using gauss elimination >> do some row operations to get the ones to easily solve for the inverse
FOR i:0 to n-1
    FOR j:0 to n-1
      IF   j!=i
          real factor
          set factor to arr[j][i]/arr[i][i]
          FOR k:0 to 2*n-1
             set  arr[j][k] to arr[j][k]-(arr[i][k]*factor)
               // Multiply each row by a nonzero integer.
               //  here we do the row operation by multiplying the row by the factor and subtracting to get Pivots
               //  we apply this to the whole augmented matrix
          END FOR
      END IF
    END FOR
END FOR
// Divide each row by the diagonal element
FOR i:0 to n-1
    real factor
    set factor to arr[i][i] // diagonal element
        FOR j:0 to 2*n-1
             set arr[i][j] to arr[i][j]/factor
        END FOR
END FOR
// print the inverse
FOR i:0 to n-1
    FOR j:n to 2*n-1
       OUTPUT arr[i][j]
    END FOR
END FOR


