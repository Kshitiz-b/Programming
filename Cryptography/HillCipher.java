package Cryptography;

import java.util.Scanner;

class hillCipher {

    static void getKeyMatrix(String key, int keyMatrix[][]) {
        int k = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                keyMatrix[i][j] = (key.charAt(k)) % 65;
                k++;
            }
        }
    }

    static int modInverse(int a, int m) {
        a = a % m;
        for (int x = 1; x < m; x++) {
            if ((a * x) % m == 1) {
                return x;
            }
        }
        return 1;
    }

    static void getCofactor(int keyMatrix[][], int temp[][], int p, int q, int n) {
        int i = 0, j = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (row != p && col != q) {
                    temp[i][j++] = keyMatrix[row][col];

                    if (j == n - 1) {
                        j = 0;
                        i++;
                    }
                }
            }
        }
    }

    static int determinant(int keyMatrix[][], int n, int N) {
        int D = 0;

        if (n == 1)
            return keyMatrix[0][0];

        int [][]temp = new int[N][N];
        int sign = 1;

        for (int f = 0; f < n; f++) {
            getCofactor(keyMatrix, temp, 0, f, n);
            D += sign * keyMatrix[0][f] * determinant(temp, n - 1, N);
            sign = -sign;
        }

        return D;
    }

    static void adjoint(int keyMatrix[][], int adj[][], int N) {
        if (N == 1) {
            adj[0][0] = 1;
            return;
        }

        int sign = 1;
        int [][]temp = new int[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                getCofactor(keyMatrix, temp, i, j, N);
                sign = ((i + j) % 2 == 0) ? 1 : -1;
                adj[j][i] = (sign) * (determinant(temp, N - 1, N));
            }
        }
    }

    static boolean getInverseKeyMatrix(int keyMatrix[][], int inverseKeyMatrix[][], int N) {
        int det = determinant(keyMatrix, N, N);
        if (det == 0) {
            System.out.print("Singular matrix, can't find its inverse");
            return false;
        }

        int invDet = modInverse(det, 26);

        int [][]adj = new int[N][N];
        adjoint(keyMatrix, adj, N);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                inverseKeyMatrix[i][j] = (adj[i][j] * invDet) % 26;

        return true;
    }

    static void encrypt(int cipherMatrix[][], int keyMatrix[][], int messageVector[][]) {
        int x, i, j;
        for (i = 0; i < 3; i++) 
        {
            for (j = 0; j < 1; j++)
            {
                cipherMatrix[i][j] = 0;
         
                for (x = 0; x < 3; x++)
                {
                    cipherMatrix[i][j] += keyMatrix[i][x] * messageVector[x][j];
                }
         
                cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
            }
        }
    }

    static void decrypt(int plainMatrix[][], int inverseKeyMatrix[][], int cipherMatrix[][]) {
        int x, i, j;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 1; j++) {
                plainMatrix[i][j] = 0;

                for (x = 0; x < 3; x++) {
                    plainMatrix[i][j] += inverseKeyMatrix[i][x] * cipherMatrix[x][j];
                }

                plainMatrix[i][j] = Math.floorMod(plainMatrix[i][j], 26);
            }
        }
    }

    static void HillCipher(String message, String key, boolean encrypt) {
        int [][]keyMatrix = new int[3][3];
        getKeyMatrix(key, keyMatrix);

        int [][]messageVector = new int[3][1];
        int [][]cipherMatrix = new int[3][1];
        String processedText = "";

        if (encrypt) {
            for (int i = 0; i < 3; i++)
                messageVector[i][0] = (message.charAt(i)) % 65;

            encrypt(cipherMatrix, keyMatrix, messageVector);

            for (int i = 0; i < 3; i++)
                processedText += (char)(cipherMatrix[i][0] + 65);
        } else {
            int [][]inverseKeyMatrix = new int[3][3];
            if (getInverseKeyMatrix(keyMatrix, inverseKeyMatrix, 3)) { 
                for (int i = 0; i < 3; i++)
                    messageVector[i][0] = (message.charAt(i)) % 65;

                decrypt(cipherMatrix, inverseKeyMatrix, messageVector);

                for (int i = 0; i < 3; i++)
                    processedText += (char)(cipherMatrix[i][0] + 65);
            }
        }

        System.out.println("Processed Text: " + processedText);
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.println("Enter the message:");
            String message = scanner.nextLine();

            System.out.println("Enter the key:");
            String key = scanner.nextLine();

            System.out.println("Encrypt or Decrypt? (E/D):");
            String mode = scanner.nextLine();

            boolean encrypt = mode.equalsIgnoreCase("E");

            HillCipher(message, key, encrypt);
        }
    }
}
