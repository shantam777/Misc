//PROBLEM : See PDF of same name.
import java.util.*;

public class MinTransCost {
	public static void main(String[] args)
	{
		int addc=0,delc=0,repc=0,i=0,num=0;
		String origs,anags;
		Scanner sc = new Scanner(System.in);
		System.out.print("\nEnter the number of inputs : ");
		num=sc.nextInt();
		for(i=0;i<num;i++)
		{
			System.out.print("\nEnter the cost for addition : ");
			addc=sc.nextInt();
			System.out.print("\nEnter the cost for deletion : ");
			delc=sc.nextInt();
			System.out.print("\nEnter the cost for replacement : ");
			repc=sc.nextInt();
			System.out.print("\nEnter the original string : ");
			origs=sc.next();
			System.out.print("\nEnter the wrong string : ");
			anags=sc.next();
			calculateCost(origs,anags,addc,delc,repc);
		}
		sc.close();
	}
	static void calculateCost(String origs, String anags,int addc, int delc, int repc)
	{
		int sizeo,sizea,cost=0,i,j,aindex=0,temp;
		StringBuilder orig = new StringBuilder(origs);
		StringBuilder anag = new StringBuilder(anags);
		sizeo=orig.length();
		sizea=anag.length();
		temp=sizea;
		if(sizea==sizeo)
		{
			for(i=0;i<sizeo;i++)
			{
				for(j=0;j<temp;j++)
				{
					if(orig.charAt(i)==anag.charAt(j))
					{
						aindex++;
						temp--;
						anag.deleteCharAt(j);
						break;
					}
				}
			}
			if(aindex==sizeo)
				System.out.println("The input wrong string is an anagram of the original string!");
			else
				System.out.println("The input wrong string is not an anagram of the original string! Transformation would be required...");
		}
		else if(sizea>sizeo)
			cost+=delc*(sizea-sizeo);
		else
			cost+=addc*(sizeo-sizea);
		if((sizeo-aindex)*(delc+addc)<(sizeo-aindex)*repc)
			cost+=(sizeo-aindex)*(delc+addc);
		else
			cost+=(sizeo-aindex)*repc;
		System.out.println("Minimum cost of transformation = " + cost);	
	}
}
