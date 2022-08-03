var $images = null;

        $(document).ready(function(){
            init();
            initEvent();
        })

        function init(){
            $images = $("#container1 img");
        }
        function initEvent(){
            $("#btnStart").click(function(){
                showImage();
            })
        }
        function showImage(){
            var length = $images.length;
                // 이미지 나열하기
            for(var i=0 ; i<length ; i++){
                // eq()를 이용하여 index에 맞는 이미즈를 저장한다.
                var $img = $images.eq(i);
                // 위치의 값을 구하기
                var x = 100 + ((i % 3)*200);
                var y = 100 + (parseInt((i/3))* 200);

                // 이미지의 위치를 설정하는 부분
                $img.css({
                    left : x,
                    top : y
                });
            }
        }

        // $(document).ready(function(){
        //     // 배열로 이미지들을 받고 있ㄷ.
        //     var $images = $("#container1 img");
            
        //     $("#btnStart").click(function(){
        //         // 이미지의 개수 구하기
        //         var length = $images.length;
        //         // 이미지 나열하기
        //         for(var i=0 ; i<length ; i++){
        //             // eq()를 이용하여 index에 맞는 이미즈를 저장한다.
        //             var $img = $images.eq(i);
        //             // 위치의 값을 구하기
        //             var x = 100 + ((i % 3)*200);
        //             var y = 100 + (parseInt((i/3))* 200);

        //             // 이미지의 위치를 설정하는 부분
        //             $img.css({
        //                 left : x,
        //                 top : y
        //             });
        //         }
        //     });
        // })