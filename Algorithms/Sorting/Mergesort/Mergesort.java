public class Mergesort {
	private static void merge(int[] arr, int[] aux, int lo, int mid, int hi) {
		for(int i = lo; i <= hi; i++) aux[i] = arr[i];

		int i = lo, j = mid + 1;

		for(int k = lo; k <= hi; k++) {
			if(j > hi) arr[k] = aux[i++];
			else if(i > mid) arr[k] = aux[j++];
			else if(aux[i] < aux[j]) arr[k] = aux[i++];
			else arr[k] = aux[j++];
		}
	}

	private static void sort(int[] arr, int[] aux, int lo, int hi) {
		if(hi <= lo) return;
		int mid = (hi - lo) / 2 + lo;
		sort(arr, aux, lo, mid);
		sort(arr, aux, mid + 1, hi);
		merge(arr, aux, lo, mid, hi);
	}

	public static void sort(int[] arr) {
		int[] aux = new int[arr.length];
		sort(arr, aux, 0, arr.length - 1);
	}
}