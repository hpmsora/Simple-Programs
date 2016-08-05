import java.util.Scanner;

public class FactoringNumber {

    public static void main(String args[]) {

	Scanner scan = new Scanner(System.in);

	int[] arr;

	int count;
	int x = 0, i;

	while(true) {
	    count = 0;
	    arr = new int[100];
	    System.out.println("Input the number: (0 for exit)");
	    x = scan.nextInt();
	    
	    if(x == 0)
		break;

	    for(i = 2; i < x; i++) {
		
		if((x % i) == 0) {
		    arr[count] = i;
		    count++;
		    
		}
	    }
	    if(count == 0)
		System.out.println("Prime Number");
	    else {
		System.out.print("1 ");
		for(i = 0; i < count; i++)
		    System.out.print(arr[i] + " ");
		System.out.println(x);
	    }
	    System.out.print("\n");
	}

    }
}