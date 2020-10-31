// priority queue implementation in java

import java.util.*;
class Pq
{
	public static void main(String ab[])
	{
		PriorityQueue<Integer> p=new PriorityQueue<Integer>();		
	//	System.out.println(p.poll());		// should return null
	//	System.out.println(p.remove());		   should return error
	//	System.out.println(p.peek());		// should return null
	//	System.out.println(p.element());	// should return error
		int a[]={2,0,3,4,7,6,5,9,8,1};
		for(int i=0;i<a.length;i++)
		{
			p.offer(a[i]);
			System.out.println(p);
		}
		System.out.println(p);
		System.out.println(p.poll());
		System.out.println(p);
		System.out.println(p.remove());
	//	System.out.println(p.peek());
	//	System.out.println(p.element());
		System.out.println(p);


		PriorityQueue<Integer> q=new PriorityQueue<Integer>();
		for(int i=0;i<10;i++)
		{
			q.offer(i);
			System.out.println(q);
		}
		System.out.println(q.poll());
		System.out.println(q);
	}
}