#####################
SFML 游戏开发代码库
#####################

本文件说明如何编译《SFML 游戏开发》书籍配套的代码。

代码库包含 10 个子目录，分别对应书籍的 10 个章节。例如，`02_Resources` 包含第 2 章的代码。所有章节的代码可以一次性编译。

---

## 一、安装 CMake

请安装 **CMake**，推荐使用带图形界面的 **CMake-GUI**。
- 下载地址：[www.cmake.org](https://www.cmake.org)
- Linux 用户：可通过包管理器安装 `cmake-gui`（例如，Ubuntu 使用 `sudo apt install cmake-gui`）。

---

## 二、安装 SFML

1. 下载 **SFML 2** 库（官方网站：[www.sfml-dev.org](https://www.sfml-dev.org)）。
   - 推荐：使用官方提供的预编译版本，直接下载即可，安装更便捷。
   - 高级选项：你也可以自行编译 SFML。编译完成后，需执行 `make install`（Linux）或在 Visual Studio 中编译 `INSTALL` 项目。详情请参考 SFML 官网的在线教程。
2. 安装完成后，你将获得一个包含以下子目录的 SFML 安装目录：
   - `include`：存放 SFML 的头文件。
   - `lib`：存放 SFML 的库文件（二进制文件）。
   - 示例路径：
     - Windows：`C:\SFML`
     - Linux：`/usr/local`

---

## 三、生成编译配置

1. 启动 **CMake-GUI**。
2. 在“源代码路径”（Where is the source code）字段中，输入包含本 `README.md` 文件的项目目录路径。
   - 请使用正斜杠（`/`），例如：`D:/SFML-Game-Development-Book`。
3. 在“编译输出路径”（Where to build the binaries）字段中，输入一个不同的路径，用于存放项目的临时编译文件。
   - 建议新建一个空目录，例如：`D:/SFML-Build`。
4. 点击 **Configure** 按钮，选择你的编译器（例如 Visual Studio、MinGW 或 GCC）。
5. 如果出现错误提示“未找到 SFML”（这是正常情况），请在 `SFML_ROOT` 字段中输入 SFML 的安装路径，即包含 `include` 和 `lib` 子目录的目录（例如：`C:/SFML` 或 `/usr/local`）。
6. 设置 `CMAKE_BUILD_TYPE` 为以下之一：
   - `Release`：推荐，生成优化后的程序，运行效率更高（通常为默认值）。
   - `Debug`：用于调试，适合查找代码问题。
7. 对于 Windows 用户，选择 SFML 链接方式：
   - 勾选 `SFML_STATIC_LIBRARIES`：静态链接，生成独立的可执行文件，无需额外 DLL。
   - 不勾选：动态链接，需提供 SFML 的 DLL 文件。
8. 设置 `CMAKE_INSTALL_PREFIX` 为最终程序的安装路径（例如：`D:/SFML-Install`）。
   - 建议选择一个新目录，可以是项目目录的子目录。
9. 再次点击 **Configure**，确认无错误提示。
10. 点击 **Generate**，生成编译所需的文件。

---

## 四、编译代码

1. 切换到“编译输出路径”目录（即你在“编译输出路径”中指定的目录，例如 `D:/SFML-Build`）。
2. 此时，你会看到编译所需的文件。根据你的编译器，执行以下操作：
   - **Linux 或 macOS（使用 g++ 或 clang）**：
     - 打开终端，进入编译目录，运行：
       ```bash
       make install
       ```
   - **Windows（使用 MinGW）**：
     - 打开终端，运行：
       ```bash
       mingw32-make install
       ```
   - **Windows（使用 Visual Studio）**：
     - 打开编译目录中的 `.sln` 解决方案文件。
     - 在 Visual Studio 中选择“Release”或“Debug”模式。
     - 找到 `INSTALL` 项目，右键选择“生成”（Build）。
   - **其他集成开发环境（IDE）**：
     - 操作类似，找到并编译 `INSTALL` 项目。
3. 编译完成后，可执行文件和资源文件将输出到 `CMAKE_INSTALL_PREFIX` 指定的目录（例如：`D:/SFML-Install`）。

---

## 五、编译结果

- 各章节的可执行文件位于 `CMAKE_INSTALL_PREFIX` 指定的安装目录（例如：`D:/SFML-Install`）。
- 如果你想查看源代码：
  - 项目根目录包含 10 个子目录（`01_Intro` 至 `10_Network`），分别对应书籍的章节。
  - 每个子目录包含：
    - 源文件（`.cpp`）和头文件（`.hpp`）：实现游戏功能的 C++ 代码。
    - 资源文件（`media`）：如图片、音效等。

---