$(document).ready(function(){
    var str = window.prompt("문자열을 입력하세요.");
    var $print = $("#print");
    var index = 0;
    var timerID = setInterval(function(){
        var ch = str.charAt(index);
        $print.text(ch);
        index++;

        if(index > str.length){
            clearInterval(timerID);
            alert("문자열 출력 종료!")
        }
    }, 1000);
});