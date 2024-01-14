<script>
	import { onMount } from 'svelte';
	import MultipleImages from '$lib/MultipleImages.svelte';
	import { getFirebassApp, getFirebaseInfo, signIntoFirebase } from '$lib//firebase.js';
	import { redirect } from '@sveltejs/kit';
	const headerImage = {
		imageURL: '$static/path-to-your-top-image.jpg',
		altText: 'Top Image',
		newLine: true
	};
	const gotchiImage = {
		imageURL: '$static/path-to-your-second-image.jpg',
		altText: 'Second Image',
		newLine: true
	};
	const images = [headerImage, gotchiImage];
	const app = getFirebassApp();
	const {auth} = getFirebaseInfo(app);
	console.log(auth.currentUser);
</script>

<header>
	<MultipleImages {images} />
</header>		
<main>
	<slot />
</main>
<footer>
	<nav>
		<button>Click Me</button>
	</nav>
</footer>

<style>
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
		border-radius: 4px;
		cursor: pointer;
	}
	button:hover {
		background-color: #45a049; /* Darker shade on hover */
	}
</style>
