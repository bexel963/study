$(document).ready(function(){
    var $contents = $("#contents");
    var cnt = 0;
    
    // 익명함수 풀이
    // setInterval(function(){
    //     cnt++;
    //     $contents.text(cnt);    // 태그 요소의 영역에 출력
    // }, 1000);

    // 일반함수 풀이
    function addCnt() {
        cnt++;
        $contents.text(cnt);
    }
    setInterval(addCnt, 1000);
});