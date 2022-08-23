import java.util.*;
public class strFunc
{
    static void upper()
    {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.printf("Enter a String\n");
            String input = sc.nextLine();
            System.out.println(input.toUpperCase());
        }
    }
    static void trim()
    {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.printf("Enter a String\n");
            String input = sc.nextLine();
            System.out.println(input.trim());
        }
    }
    static void palindrome()
    {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.printf("Enter a String\n");
            String str = sc.next();
            String revStr="", equal="";
            int strLen = str.length();
            int eqLen;
            
            for (int i = (strLen-1) ; i>=0 ; i--)
            {
                revStr += str.charAt(i);
            }
            
            if (str.toLowerCase().equals(revStr.toLowerCase()))
            {
                for (int i = (strLen-1) ; i>=0 ; i--)
                {
                    if(str.charAt(i) == revStr.charAt(i))
                    equal += str.charAt(i);
                }
                eqLen = equal.length();
                System.out.println(equal);
                System.out.println(eqLen);
            }
        }
    }
    static void mostFreq()
    {
        Scanner sc = new Scanner(System.in);
        System.out.printf("Enter a String\n");
        String str = sc.next();
        char minChar = str.charAt(0), maxChar = str.charAt(0);
        int i, j, min, max;
        int strLen = str.length();
        
        int[] freq = new int[strLen];
        char string[] = str.toCharArray();
        
        for (i=0;i<string.length;i++)
        {
            freq[i] = 1;
            for (j=i+1;j<string.length;j++)
            {
                if (string[i] == string[j] && string[i] != ' ' && string[i] != '0')
                {
                    freq[i]++;
                    string[j] = '0';  
                } 
            }
        }
        min = max = freq[0];
        
        for(i=0;i<freq.length;i++)
        {
            if(min>freq[i]&&freq[i]!='0'){
                min = freq[i];
                minChar = string[i];
            }
            if (max<freq[i]){
                max=freq[i];
                maxChar=string[i];
            }
            System.out.println("MIN: "+minChar);
            System.out.println("MAX: "+maxChar);
        }
        
    }
    public static void main(String[] args)
    {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("Enter your Choice: ");
            int n = sc.nextInt();
            
            switch(n)
            {
                case(1):
                    upper();
                    break;
                
                case(2):
                    trim();
                    break;
                
                case(3):
                    palindrome();
                    break;
                case(4):
                    mostFreq();
                    break;
                
                    
            }
        }
    }
}