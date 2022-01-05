fun main() {
    val br = System.`in`.bufferedReader()
    val t = br.readLine()!!.toInt()

    repeat(t) {
        var (a, b) = br.readLine()!!.split(" ").map { it.toInt() }
        var ans = 1
        a %= 10
        while(b-- != 0) {
            ans = ans * a % 10
        }

        println(if(ans == 0) 10 else ans)
    }
}