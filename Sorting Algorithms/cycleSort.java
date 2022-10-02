import java.util.Arrays;

public class cycleSort {
    public static void main(String[] args) {
        int[] arr= {-4,-1,0,3,10};
        cycle(arr);
    }
    static void cycle(int[] arr){
        int i= 0;
        while (i< arr.length){
            int correct= arr[i];
            if(arr[i] < arr.length && arr[i] != arr[correct]){
                swap(arr, i, correct);
            }
            else {
                i++;
            }
        }
        System.out.println(Arrays.toString(arr));
    }

    static void swap(int[] arr, int first, int second) {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }


}
