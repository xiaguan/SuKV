---
title: README
date: 2023-01-05T22:19:40Z
lastmod: 2023-01-05T22:30:35Z
---

# README

# SuKV --- LevelDB's morder version

init的readme就写中文的吧，后面英语好好学再改成英文的。

1. 为什么开这个仓库呢？

    我最近在读leveldb，也不只是因为对存储感兴趣，某种程度上它是最值得学习的源码，命名，构建，注释等等，包括skiplist的无锁编程，优点太多我只能说牛牛牛。又因为我最近看了非常多的C++20 特性 ： coroutine (和io_uring结合，提供io服务)，module(取代传统的头文件)，包括一些新工具：比如xmake，写起来确实比cmake好一些。学了那么多新东西，总要有东西练手。不能整天搁那hello world是把。
2. 未来计划

    这个项目可能在二月份结束，后面加点解析变成一个关系型数据库，当然不会写特别大，又或者加点共识算法，变成分布式K/V数据库，包括一些性能测试，毕竟它是十年前的代码？不一定适合现在的架构。

todo list :

* 要用clang-format,clang-tidy,clang-lint规整自己的代码，保持同一的风格，别人阅读就不会太难受。
* 注释风格，现在的注释还比较垃圾，以后多注意
* C++新加的特性“属性”，用来标识类似函数返回值不能忽略等等。

至于你想这个项目编译起来，你需要使用vs 2022 preview (并且按照官网开启标准库模块) 和 xmake(尽可能新的版本)。
