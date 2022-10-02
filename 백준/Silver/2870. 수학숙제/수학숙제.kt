package com.dnd.niceteam

var ret = ""
val list = mutableListOf<String>()
fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readLine().toInt()

    repeat(n) {
        val str = br.readLine()
        ret = ""
        for (c in str) {
            if (c in '0'..'9') ret += c
            else go()
        }
        go()
    }
    list.sortWith(compareBy({ it.length }, { it }))
    list.forEach { println("$it") }
}

fun go() {
    if (ret.isNotEmpty()) {
        while (true) {
            if (ret.isNotEmpty() && ret.first() == '0') ret = ret.substring(1)
            else break
        }
        if (ret.isEmpty()) ret = "0"
        list.add(ret)
        ret = ""
    }
}