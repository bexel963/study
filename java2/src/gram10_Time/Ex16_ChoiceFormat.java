package gram10_Time;

import java.text.ChoiceFormat;

// 특정 범위에 속하는 값을 문자열로 변환
// 연속적, 불연속적인 범위의 값들을 처리하는 데 있어서 if문이나 switch문은 적절치 못한 경우가 많은데, 이 때 ChoiceFormat을 잘 사용하면,
// 복잡하게 처리될 수밖에 없었던 코드를 간단하고 직관적으로 만들 수 있다.
public class Ex16_ChoiceFormat {
    public static void main(String[] args) {

        double[] limits = { 60, 70, 80, 90 };
        String[] grades = { "D", "C", "B", "A" };
        int[] scores = { 100, 95, 88, 70, 52, 60, 70 };

        // 경계(limits)는 반드시 오름차순으로 정렬 되어있어야 한다.
        // 치환 될 문자열의 개수(grades)는 경계값에 의해 정의된 범위의 개수와 일치해야한다.
        ChoiceFormat form = new ChoiceFormat(limits, grades);
        for(int i=0 ; i<scores.length ; i++) {
            System.out.println(scores[i] + ": " + form.format(scores[i]));
        }

        // #은 경계값을 범위에 포함시키지만, <는 포함시키지 않는다.
        System.out.println("\n-------------------------\n");

        String pattern = "60#D|70#C|80<B|90#A";
        int[] points = { 91, 90, 80, 88, 70, 52, 60 };

        ChoiceFormat form2 = new ChoiceFormat(pattern);

        for(int i=0 ; i<points.length ; i++) {
            System.out.println(points[i] + ": " + form2.format(points[i]));
        }
    }
}
