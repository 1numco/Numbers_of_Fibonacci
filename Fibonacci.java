import java.util.Scanner;

public class Fibonacci {
	
	static int[][] matrix_multiply(int[][] mat1, int[][] mat2)
	{
		int[][] mat3;
		mat3 = new int[2][2];
		mat3[0][0] = mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0];
		mat3[0][1] = mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1];
		mat3[1][0] = mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0];
		mat3[1][1] = mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1];
		return mat3;
	}
	
	static int[][] pow(int[][] mat, int n)
	{
		int[][] mat1;
		mat1 = new int[2][2];
		mat1[0][0] = 1;
		mat1[0][1] = 0;
		mat1[1][0] = 0;
		mat1[1][1] = 1;
		if (n == 0)
			return mat1;
		if (n == 1)
			return mat;
		if (n % 2==1)
		{
			return matrix_multiply(mat, pow(matrix_multiply(mat, mat), n / 2));
		}
		else
		{
			return pow(matrix_multiply(mat, mat), n / 2);
		}
	}
	
	static int fib(int[][] mat,int n)
	{
		return pow(mat,n - 1)[0][0];
	}

	public static void main(String[] args) {
		int[][] mat;
		mat = new int[2][2];
		int n = 0;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the serial number: ");
		n=in.nextInt();
		mat[0][0] = 1;
		mat[0][1] = 1;
		mat[1][0] = 1;
		mat[1][1] = 0;
		System.out.println("Your desired number of Fibonacci: "+fib(mat,n));
	}

}
