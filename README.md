# 🎮 Candy Console: A C++ Crush Adventure

A terminal-based Candy Crush clone built from scratch in C++ during my first semester at FAST NUCES. It features grid-based matching, score calculation, real-time cursor control using arrow keys, and a countdown timer — all in a classic console interface.

---

## 🧠 What It Does

- Match-3 style candy game in a 2D grid
- Cursor movement with arrow keys
- Swap candies using W (up), S (down), A (left), D (right)
- Score calculation based on match types
- Auto-drop candies after a match
- Shuffle grid when no moves are left
- Timer for both Easy (60s) and Hard (40s) modes
- Colorful candy display using `Windows.h`

---

## 🧱 Project Structure

* [include](./include)
  * [CandyCrushLogic.h](./include/CandyCrushLogic.h)
  * [CandyCrushTimer.h](./include/CandyCrushTimer.h)
* [src](./src)
  * [CandyCrushConsole.cpp](./src/CandyCrushConsole.cpp)
  * [CandyCrushLogic.cpp](./src/CandyCrushLogic.cpp)
  * [CandyCrushTimer.cpp](./src/CandyCrushTimer.cpp)
* [LICENSE](./LICENSE)
* [README.md](./README.md)


---

## 🕹️ Controls

- **Arrow Keys**: Move the cursor (`X`)
- **W / A / S / D**: Swap candies in Up / Left / Down / Right direction
- **Left Arrow**: Select menu options

---

## 🍬 Match Types & Points

- Horizontal / Vertical match → +10
- Diagonal match → +20
- L-shape (5-candy) match → +25  
*(Auto-detected and scored)*

---

## 🏁 Getting Started

1. **Clone the repository**

```bash
git clone https://github.com/your-username/CandyConsole-Cpp.git
cd CandyConsole-Cpp
```

2. **Compile using any C++ compiler (supports Windows.h)**

```bash
g++ src/*.cpp -I include -o CandyConsole.exe
```

3. **Run it**

```bash
./CandyConsole.exe

```

⚠️ This game is designed for Windows OS as it uses <Windows.h> for colored output.

---


## 🧠 Lessons Learned
This project taught me:

- Fundamentals of game loops and input handling

- Working with multi-dimensional arrays

- Debugging complex logic without visual tools

- The joy of making things fun with just code ✨

---

## 📸 Screenshots & Demo
Check out a short demo here!!!

---

## 🙌 Authors
- Junaid A. Chaudhary
- Muhammad Ahmed

---

## 📄 License

This project is licensed under the [MIT License](./LICENSE).

You are free to use, modify, and distribute this project with proper attribution. See the [LICENSE](./LICENSE) file for full terms.

---

## 📬 Contact

If you have questions, feedback, or just want to connect:

- 📧 Email: junaidch413@gmail.com  
- 💼 LinkedIn: [Junaid A. Chaudhary](https://www.linkedin.com/in/your-profile/)
- 🌱 GitHub: [@your-username](https://github.com/your-username)

Feel free to fork the repo, open issues, or suggest improvements. Let’s build better code together!
