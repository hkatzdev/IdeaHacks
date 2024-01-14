<header>
	<img src="/Compost.png" alt="Logo" id="logo" class="automaticResize" />
</header>
<main>
	<slot />
</main>
<footer>
	<nav>
		<button
			on:click={() => {
				alert('This project was made by the Pierce Team :)');
			}}>Who made this?</button
		>
	</nav>
</footer>

<style>
	@import '$lib/styles/automaticResize';
	:global(html) {
		min-width: 100vw;
		min-height: 100vh;
		margin: 0;
		font-family: Arial, sans-serif;
		background-color: #f7f7f7;
	}
	:global(body) {
		min-width: max(85vw, calc(100vw - 10em)); /* Adjust the width as needed */
		min-height: 100vh; /* Adjust the width as needed */
		margin: auto;
	}
	:global(body),
	header,
	main,
	footer {
		display: flex;
		flex-direction: column;
		justify-content: center;
		align-items: center;
	}
	header {
		text-align: center;
	}
	main {
		flex: 1;
	}
	button {
		margin: auto; /* Centers the button */
		background-color: #4caf50;
		color: white;
		border: none;
		border-radius: 0.25rem;
		cursor: pointer;
	}
	button:hover {
		background-color: #45a049; /* Darker shade on hover */
	}
	#logo {
		max-width: 60vw;
		max-height: 30vh;
	}
</style>
