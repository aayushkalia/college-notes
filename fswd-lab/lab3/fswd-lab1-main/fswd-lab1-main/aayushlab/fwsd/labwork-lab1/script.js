function toggleMenu() {
  document.getElementById("navLinks").classList.toggle("show");
}

function validateForm() {
  const name = document.getElementById("name").value;
  const email = document.getElementById("email").value;
  const password = document.getElementById("password").value;
  const error = document.getElementById("error");

  if (name === "" || email === "" || password === "") {
    error.innerText = "All fields are required";
    return false;
  }

  error.innerText = "";
  alert("Form submitted successfully");
  return true;
}
