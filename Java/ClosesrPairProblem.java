import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class ClosestPairProblem {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ArrayList<Coordinates> points = new ArrayList<Coordinates>(100);

		System.out.println("Enter the no. of Points : ");
		int n = sc.nextInt();
		System.out.println("Enter " + n + " Points : ");
		for (int i = 1; i <= n; i++) {
			System.out.println("Enter the Coordinates of Point" + i + " : ");
			int x = sc.nextInt();
			int y = sc.nextInt();
			points.add(new Coordinates(x, y));
		}
		System.out.println("Given Points are : ");
		for (int i = 0; i < points.size(); i++) {
			System.out.println("(" + points.get(i).x + "," + points.get(i).y + ")");
		}
		System.out.println("The Minimum Distance is : " + closestPair(points, points.size()));

	}

	public static float closestPair(ArrayList<Coordinates> pts, int n) {
		ArrayList<Coordinates> sortedX = new ArrayList<Coordinates>(100);
		ArrayList<Coordinates> sortedY = new ArrayList<Coordinates>(100);
		for (int i = 0; i < pts.size(); i++) {
			sortedX.add(pts.get(i));
		}
		for (int i = 0; i < pts.size(); i++) {
			sortedY.add(pts.get(i));
		}
		Collections.sort(sortedX, new xCoordinateComparator());
		Collections.sort(sortedY, new xCoordinateComparator());
		return findClosest(sortedX, sortedY, n);

	}

	public static float findMinDist(ArrayList<Coordinates> pts, int n) { // find minimum distance between two points in a set

		float min = (float) Double.POSITIVE_INFINITY;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (dist(pts.get(i), pts.get(j)) < min)
					min = dist(pts.get(i), pts.get(j));
		return min;
	}

	public static float findClosest(ArrayList<Coordinates> sortedX, ArrayList<Coordinates> sortedY, int n) {
		if (n <= 3)
			return findMinDist(sortedX, n);
		int mid = n / 2;
		Coordinates midPoint = sortedX.get(mid);
		ArrayList<Coordinates> leftSortedY = new ArrayList<Coordinates>(100);
		ArrayList<Coordinates> rightSortedY = new ArrayList<Coordinates>(100);
		int leftIndex = 0;
		int rightIndex = 0;

		for (int i = 0; i < n; i++) { // separate y sorted points to left and right
			if (sortedX.get(i).x <= midPoint.x) {
				leftSortedY.add(leftIndex, sortedY.get(i));
				leftIndex++;
			} else {
				rightSortedY.add(rightIndex, sortedY.get(i));
				rightIndex++;
			}

		}

		float leftDist = findClosest(sortedX, leftSortedY, mid);
		float rightDist = findClosest(sortedY, rightSortedY, n - mid);
		float dist = Math.min(leftDist, rightDist);

		ArrayList<Coordinates> strip = new ArrayList<Coordinates>(n);
		int j = 0;

		for (int i = 0; i < n; i++)
			if (Math.abs(sortedY.get(i).x - midPoint.x) < dist) {
				strip.add(j, sortedY.get(i));
				j++;
			}
		return Math.min(dist, stripClose(strip, j, dist));

	}

	public static float stripClose(ArrayList<Coordinates> strip, int size, float d) {
		float min = d;
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size && (strip.get(j).y - strip.get(i).y) < min; ++j)
				if (dist(strip.get(i), strip.get(j)) < min)
					min = dist(strip.get(i), strip.get(j));
		return min;
	}

	public static float dist(Coordinates p1, Coordinates p2) {
		return (float) Math.sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
	}

}

class xCoordinateComparator implements Comparator<Coordinates> {
	public int compare(Coordinates A, Coordinates B) {
		return A.x - B.x;
	}

}

class yCoordinateComparator implements Comparator<Coordinates> {
	public int compare(Coordinates A, Coordinates B) {
		return A.y - B.y;
	}

}

class Coordinates {
	int x, y;

	Coordinates(int x, int y) {
		this.x = x;
		this.y = y;

	}
}
