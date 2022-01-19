fun main() {
    val br = System.`in`.bufferedReader()
    var (n, k) = br.readLine()!!.split(" ").map{ it.toInt() }
    var ans = 0

    while(true) {
        var cnt = 0
        var x = n
        while(x > 0) {
            if(x and 1 == 1) cnt++
            x = x.shr(1)
        }
        if(cnt <= k) break
        
        // 구매하기
        n++
        ans++
    }
    println(ans)
}