package al04;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

public class Greed {
    // 탐욕 알고리즘 예

    // ex1)
    // 지불해야 하는 값이 4720원 일 때, 1원 50원 100원 500원으로 동전의 수가 가장 적게 지불.
    // 탐욕 알고리즘으로 매 순간 최적이라고 생각되는 경우를 선택한다.
    public void coinFunc(Integer price, ArrayList<Integer> coinList) {
        Integer totalCoinCount = 0;
        Integer coinNum = 0;
        ArrayList<Integer> details = new ArrayList<>();

        for(int index=0 ; index<coinList.size() ; index++) {
            coinNum = price / coinList.get(index);
            totalCoinCount += coinNum;
            price -= coinNum * coinList.get(index);
            details.add(coinNum);
            System.out.println(coinList.get(index) + "원: " + coinNum + "개");
        }
        System.out.println("총 동전 갯수: " + totalCoinCount);
    }

    // ex2) 배낭문제
    // 무게 제한이 k인 배낭에 최대 가치를 가지도록 물건을 넣는다.
    // 물건은 쪼갤 수 있으므로 물건의 일부분이 배낭에 넣어질 수 있음
    /*
        물건(i)   물건1     물건2     물건3     물건4     물건5
        무게(w)    10        15       20        25       30
        가치(v)    10        12       10        8         5
    */
    // 무게 1당 가치가 가장 높은 물건1을 탐욕알고리즘에 의해 먼저 넣는다. ( 가치 / 무게 )

    // <구현>
    // 2. 무게당 가치를 계산 후 높은 순으로 정렬
    public void knapsackFunc(Integer[][] objList, double capacity) {
        double totalValue = 0.0;
        double fraction = 0.0;  // 해당 물건이 가방에 들어가 있는 비율

        // 무게당 가치 순 으로 정렬
        Arrays.sort(objList, new Comparator<Integer[]>(){
            @Override
            public int compare(Integer[] objItem1, Integer[] objItem2) {
                return (objItem2[1] / objItem2[0]) - (objItem1[1] / objItem1[0]);
            }
        });

        // 가치가 높은 물건 순으로 정렬 되었기 때문에 차례로 가방에 넣으면 된다.
        for(int index=0 ; index<objList.length ; index++) {
            // 물건을 쪼갤 필요가 없을 때
            if((capacity - (double)objList[index][0]) > 0) {
                capacity -= (double)objList[index][0];
                totalValue += (double)objList[index][1];
                System.out.println("무게: " + objList[index][0] + ", 가치: " + objList[index][1]);
            // 물건을 쪼개야 할 때
            } else {
                fraction = capacity / (double)objList[index][0];
                totalValue += (double)objList[index][1] * fraction;
                System.out.println("무게: " + objList[index][0] + ", 가치: " + objList[index][1] + ", 비율: " + fraction);

                // 가치가 높은 물건이 다 못 들어가니 낮은 물건은 하나도 못 들어가니까 끝낸다.
                break;
            }
        }
        System.out.println("총 담을 수 있는 가치: " + totalValue);

    }
}










