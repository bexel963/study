// 1~100 까지 합계
var sum = 0;
var num = 1;

var start = confirm("작업을 진행햘까요?");
do{
    if(start == true){
        sum += num;
        ++num;
    }else{
        break;
    }
}
while(num<101)
if(start == true)
    document.write("<h2> 1부터 100까지의 합은 " + "<strong>" + sum + "</strong> 입니다. </h2>" );