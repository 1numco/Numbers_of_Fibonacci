import numpy
def matrix_multiply(mat1,mat2):
    mat3=numpy.zeros((2, 2))
    mat3[0][0] = mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0]
    mat3[0][1] = mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1]
    mat3[1][0] = mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0]
    mat3[1][1] = mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1]
    return mat3
def pow(mat,n):
    mat1=numpy.zeros((2, 2))
    mat1[0][0] = 1
    mat1[0][1] = 0
    mat1[1][0] = 0
    mat1[1][1] = 1
    if (n == 0):
        return mat1
    if (n == 1):
        return mat
    if (n % 2==1):
        return matrix_multiply(mat, pow(matrix_multiply(mat, mat), (n-1) / 2))
    else:
        return pow(matrix_multiply(mat, mat), n / 2)
def fib(mat,n):
    return pow(mat,n-1)[0][0]
n = int(input("Enter the serial number: "))
mat=numpy.zeros((2, 2))
mat[0][0] = 1
mat[0][1] = 1
mat[1][0] = 1
mat[1][1] = 0
print("Your desired number of Fibonacci: ")
print(int(fib(mat,n)),end="")