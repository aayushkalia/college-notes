function toggleMenu() {
  document.getElementById("navLinks").classList.toggle("show");
}

function validateForm() {
  const name = document.getElementById("name").value;
  const email = document.getElementById("email").value;
  const password = document.getElementById("password").value;
  const error = document.getElementById("error");

  if (name === "" || email === "" || password === "") {
    error.textContent = "All fields are required!";
    return false;
  }

  if (password.length < 6) {
    error.textContent = "Password must be at least 6 characters!";
    return false;
  }

  alert("Form submitted successfully!");
  return true;
}
