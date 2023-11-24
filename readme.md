# algo-daily

# 存在的问题

+ 错误提交不会回退导致一题有好几个 commit
+ vscode 中文编码错误

# 提交流程

## 终端

### fork 仓库

![image](https://github.com/lab530/algo-daily/assets/114394519/f11132a6-5291-418d-b798-bd5642f5f0b1)

![image](https://github.com/lab530/algo-daily/assets/114394519/516afb7c-4584-4c76-b6f3-cdf86ef0af54)

本地 clone

```sh
git clone [fork 的仓库]
```

### 提交代码

查看仓库修改

```sh
git status
```

```sh
git add file
git commit -m "your_name: 提提交信息"
git push
```

### 提交 pr

![image](https://github.com/lab530/algo-daily/assets/114394519/67a9e33f-ecea-4f0d-b052-a22d21581155)

## GitHub Desktop

1. 同上，fork 一份到自己的用户下
2. 在 GH Desktop 里 clone 你自己的 algo-daily 仓库
3. 创建分支（不建也可以）
4. 每天写代码打 commit 然后 push，完成了到网页上发 pr
