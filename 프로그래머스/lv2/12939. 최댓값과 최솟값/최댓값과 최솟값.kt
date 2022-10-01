class Solution {
    fun solution(s: String): String {
        var answer = ""
        var array = s.split(" ").map { it.toInt() }
        var max = array[0]
        var min = array[0]

        for(i in 1 until array.size){
            var num = array[i]

            if(num>max){
                max = num
            }
            if(num<min){
                min = num
            }
        }
        answer = "${min} ${max}"
        return answer
    }
}
