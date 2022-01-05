import kotlin.math.pow

fun main() {
    val br = System.`in`.bufferedReader()
    val arr = arrayOf("black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white")
    var str = ""
    repeat(2) {
        val value = arr.indexOf(br.readLine()!!)
        str += value.toString();
    }

    var ans = str.toLong()
    val value = arr.indexOf(br.readLine()!!)
    ans *= 10.0.pow(value).toLong()

    println(ans)
}