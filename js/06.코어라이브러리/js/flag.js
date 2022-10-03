$(document).ready(function(){
    // 배열로 국기를 저장한다.
    var imgList = ["canada.png", "england.png", "germany.png",
                "italia.png", "korea.png", "spain.png", "usa.png"];
    // 배열의 인덱스 변수를 선언과 동시에 초기화
    var index = 0;
    // 이미지 표시하기 위해서 요소를 찾아오기
    var $banner = $(".banner");

    // 1초마다 한번씩 국기가 롤링되게 끔 만들기
    setInterval(function(){
        index++;
        var imgName = imgList[index];
        $banner.attr("src", "images/" + imgName);
        if(index >= imgList.length-1){
            index = 0;
        }
    }, 1000);
});