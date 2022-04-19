const generateBtn = document.getElementById("p-btn")
const passwordField = document.querySelector(".password-text")
const clickedNavbarElements = document.querySelectorAll(".navbar-item")
const passwordSizeContainer = document.querySelector(".password-size-text")

const characterArray = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=', '[', ']', '{', '}', '|', ';', '\'', ':', ',', '.', '/', '<', '>', '?']

let size

function generatePassword() {
	let password = ""

	if (size === undefined) {
		size = 8
		passwordSizeContainer.textContent = "Current password size: " + size.toString()
	}

	for (let i = 0; i < size; i++) {
		shuffle(characterArray)
		password += characterArray[Math.floor(Math.random() * characterArray.length)]
	}
	return password
}

shuffle = (array) => {
	let i, j;
	for (i = array.length - 1; i > 0; i--) {
		j = Math.floor(Math.random() * (i + 1));
		[array[i], array[j]] = [array[j], array[i]];
	}
}

generateBtn.addEventListener("click", () => {
	passwordField.textContent = generatePassword()
})

clickedNavbarElements.forEach(element => {
	element.addEventListener("click", () => {
		size = parseFloat(element.getElementsByClassName("navbar-link")[0].textContent)
		passwordSizeContainer.textContent = "Current password size: " + size.toString()
	})
})

