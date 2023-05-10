import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

public class QuicksortToDuplicates {
	public static void sort(Integer[] arr) {
		List<Integer> list = Arrays.asList(arr);

		// The shuffle is necessary to turn improbable the worst case:
		// the elements are in decreasing order.
		// In quicksort, this would be quadratic.
		Collections.shuffle(list);
		Integer[] shuffledArr = list.toArray(new Integer[0]);
		for(int i = 0; i < arr.length; i++) arr[i] = shuffledArr[i];
		
		sort(arr, 0, arr.length - 1);
	}

	private static void sort(Integer[] arr, int lo, int hi) {
		if(hi <= lo) return;
		int i = lo, lt = lo, gt = hi;
		int cmpValue = arr[lo];

		while(i <= gt) {
			if(cmpValue > arr[i]) change(arr, lt++, i++);
			else if(cmpValue < arr[i]) change(arr, i, gt--);
			else i++;
		}

		sort(arr, lo, lt - 1);
		sort(arr, gt + 1, hi);
	}

	private static void change(Integer[] arr, int i, int j) {
		int c = arr[i];
		arr[i] = arr[j];
		arr[j] = c;
	}
}