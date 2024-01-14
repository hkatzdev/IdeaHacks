<script>
	/** @type {number[]} */
	export let liveTemps;
	/** @type {number[]} */
	export let liveMoistures;
</script>
<table>
	<tr>
		<td></td>
		<td>Temperature</td>
		<td>Moisture Level</td>
	</tr>
	<tr>
		<td>Top</td>
		<td>{liveTemps[0]}</td>
		<td>{liveMoistures[0]}</td>
	</tr>
	<tr>
		<td>Middle</td>
		<td>{liveTemps[1]}</td>
		<td>{liveMoistures[1]}</td>
	</tr>
	<tr>
		<td>Bottom</td>
		<td>{liveTemps[2]}</td>
		<td>{liveMoistures[2]}</td>
	</tr>
</table>

<style>
	@import './table';
</style>
